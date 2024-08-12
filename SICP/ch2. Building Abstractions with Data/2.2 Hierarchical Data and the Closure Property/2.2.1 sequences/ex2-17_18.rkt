#lang sicp

; exercise 2.17
(define (last-pair l)
  (if (null? (cdr l))
      (car l)
      (last-pair (cdr l))))

(last-pair (list 23 72 149 34))

(define (append a b)
  (if (null? a)
      b
      (cons (car a) (append (cdr a) b))))

; exercise 2.18
(define (reverse l)
  (if (null? (cdr l))
      l
      (append (reverse (cdr l)) (cons (car l) nil))))

(reverse (list 1 4 9 16 25))

