#lang racket

(provide (all-defined-out))

(define (in? x set)
  (cond ((null? set) false)
        ((equal? x (car set)) true)
        (else (in? x (cdr set)))))

(define (adjoin x set)
  (if (in? x set) set (cons x set)))

(define (intersection s1 s2)
  (cond ((or (null? s1) (null? s2)) '())
        ((in? (car s1) s2) (cons (car s1) (intersection (cdr s1) s2)))
        (else (intersection (cdr s1) s2))))

