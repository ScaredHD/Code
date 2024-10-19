#lang racket


(define (in? x set)
  (cond ((null? set) false)
        ((equal? x (car set)) true)
        (else (in? x (cdr set)))))

(define (adjoin x set)
  (cons x set))

(define (intersection s1 s2)
  (cond ((or (null? s1) (null? s2)) '())
        ((in? (car s1) s2) (cons (car s1) (intersection (cdr s1) s2)))
        (else (intersection (cdr s1) s2))))

(define (union s1 s2)
  (if (null? s1) s2 (cons (car s1) (union (cdr s1) s2))))

(define s1 '(1 2 3 2 1))
(define s2 '(2 2 3 3 4 4 2))

(union s1 s2)
(intersection s1 s2)
(adjoin 2 s1)
(adjoin 5 s2)
(in? 3 s2)
(in? 4 s1)