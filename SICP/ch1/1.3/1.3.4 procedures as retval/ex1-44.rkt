#lang sicp

; exercise 1.42
(define (compose f g)
  (lambda (x) (f (g x))))

; exercise 1.43
(define (iterated f n)
  (if (= n 1)
      f
      (compose f (iterated f (- n 1)))))

; =====

(define (smooth f)
  (let ((dx 0.001))
    (lambda (x)
      (/
       (+ (f (- x dx))
          (f x)
          (f (+ x dx)))
       3))))

(define (n-fold-smooth f n)
  (iterated smooth n))