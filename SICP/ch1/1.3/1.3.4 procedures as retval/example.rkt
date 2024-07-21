#lang sicp

(define (average a b)
  (/ (+ a b) 2))

(define (square x) (* x x))

(define (average-damp f)
  (lambda (x) (average x (f x))))

((average-damp square) 10)

(define (fixed-point f first-guess)
  (define tolerance 0.00001)
  (define (close-enough? v1 v2)
    (< (abs (- v1 v2)) tolerance))

  (define (try guess)
    (let ((next (f guess)))
      (if (close-enough? guess next)
          next
          (try next))))
  (try first-guess))


(define (sqrt x)
  (fixed-point (average-damp (lambda (y) (/ x y))) 1.0))

(define (cube-root x)
  (fixed-point (average-damp (lambda (y) (/ x (square y)))) 1.0))

(sqrt 4)
(cube-root 8)

