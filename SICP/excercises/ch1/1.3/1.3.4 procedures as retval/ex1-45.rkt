#lang sicp

(define (pow x n)
  (if (= n 0)
    1
    (* x (pow x (- n 1)))))

(define (avg-damp f)
  (lambda (x) (/ (+ x (f x)) 2)))

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

; exercise 1.42
(define (compose f g)
  (lambda (x) (f (g x))))

; exercise 1.43
(define (iterated f n)
  (if (= n 1)
      f
      (compose f (iterated f (- n 1)))))

; =====

(define (n-th-root-damp x n damp-count)
  (fixed-point
    ((iterated avg-damp damp-count)
      (lambda (y) (/ x (pow y (- n 1)))))
    1.0))

(define (n-th-root x n)
  (n-th-root-damp x n (floor (log n 2))))

(n-th-root 2 258)