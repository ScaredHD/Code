#lang racket

(provide (all-defined-out))

(define (in? x s)
  (cond ((null? s) false)
        ((= x (car s)) true)
        ((< x (car s)) false)
        (else (in? x (cdr s)))))

(define (intersection s1 s2)
  (if (or (null? s1) (null? s2))
      '()
      (let ([x1 (car s1)][x2 (car s2)])
        (cond ((= x1 x2) (cons x1 (intersection (cdr s1) (cdr s2))))
              ((< x1 x2) (intersection (cdr s1) s2))
              ((> x1 x2) (intersection s1 (cdr s2)))))))