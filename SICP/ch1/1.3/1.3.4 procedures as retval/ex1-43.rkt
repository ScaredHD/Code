#lang sicp

(define (repeated f n)
  (if (= n 1)
    f
    (lambda (x) (f ((repeated f (- n 1)) x)))))

; or equivalently using compose function

(define (compose f g)
  (lambda (x) (f (g x))))

(define (iterated-f f n)
  (if (= n 1)
    f
    (compose f (iterated-f f (- n 1)))))

(define (square x) (* x x))

((repeated square 2) 5)
((iterated-f square 2) 5)
