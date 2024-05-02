#lang sicp

(define (iterative-improve good-enough improve)
  (lambda (x)
    (if (good-enough x)
        (improve x)
        ((iterative-improve good-enough improve) (improve x)))))

(define (square x) (* x x))
(define (average x y) (/ (+ x y) 2))

(define (sqrt x)
  ((iterative-improve
    (lambda (y) (< (abs (- (square y) x)) 0.001))
    (lambda (y) (average y (/ x y)))
    ) 1.0))

(sqrt 2)

(define (fixed-point f init-guess)
  ((iterative-improve
    (lambda (x) (< (abs (- (f x) x)) 0.00001))
    f)
   init-guess))

(fixed-point cos 1.0)

(fixed-point (lambda (y) (+ (sin y) (cos y))) 1.0)