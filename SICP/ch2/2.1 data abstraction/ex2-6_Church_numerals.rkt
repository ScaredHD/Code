#lang sicp

; zero = f -> id
(define zero (lambda (f) (lambda (x) x)))

(define (add-1 n)
  (lambda (f) (lambda (x) (f ((n f) x)))))

; one = f -> (x -> f(x))
(define one (lambda (f) (lambda (x) (f x))))

; two = f -> ( x -> f(f(x)) )
(define two (lambda (f) (lambda (x) (f (f x)))))


; n = function that map any function f to its n-fold composition f^n
; thus
; (n f) = f^n

(define (add a b)
  (lambda (f) (lambda (x) ((a f) ((b f) x)))))

; tests

((one inc) 0)
((two inc) 0)
(((add one two) inc) 0)