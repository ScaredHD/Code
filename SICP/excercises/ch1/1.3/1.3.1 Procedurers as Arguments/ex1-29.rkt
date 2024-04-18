#lang sicp
(define (cube x) (* x x x))

(define (sum term a next b)
  (if (> a b)
    0
    (+ (term a)
       (sum term (next a) next b))))

(define (integral f a b n)
  (define h (/ (- b a) n))

  (define (term-y k)
    (f (+ a (* k h))))
  
  (define (term x)
    (+ (term-y x)
       (* 4.0 (term-y (+ x 1)))
       (term-y (+ x 2))))

  (define (next x)
    (+ x 2))

  (* (sum term 0 next (- n 2))
     (/ h 3.0)))

(integral cube 0 1 100)
(integral cube 0 1 1000)

(define pi 3.1415926535)
(integral sin 0 pi 100)
(integral sin 0 pi 1000)