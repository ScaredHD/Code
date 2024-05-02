#lang sicp

(define (average a b)
  (/ (+ a b) 2))

(define (square x) (* x x))
(define (cube x) (* x x x))

(define (average-damp f)
  (lambda (x) (average x (f x))))

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

(define (D g)
  (define dx 0.00001)
  (lambda (x) (/ (- (g (+ x dx)) (g x)) dx)))

(define (newtons-method g init-guess)
  (define (newton-transform g)
    (lambda (x) (- x (/ (g x) ((D g) x)))))

  (fixed-point (newton-transform g) init-guess))

(define (cubic a b c)
  (lambda (x) (+ (cube x) (* a (square x)) (* b x) c)))

(let ((t (newtons-method (cubic 3 2 2) 1)))
  ((cubic 3 2 2) t))