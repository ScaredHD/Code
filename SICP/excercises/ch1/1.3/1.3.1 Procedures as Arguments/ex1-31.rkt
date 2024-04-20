#lang sicp

(define (prod a b term next)
  (if (> a b)
    1
    (* (term a) (prod (next a) b term next))))

(define (prod-iter a b term next)
  (define (iter cur res)
    (if (> cur b)
      res
      (iter (next cur) (* res (term cur)))))
  (iter a 1))

(define (factorial n)
  (prod 1 n identity inc))

(factorial 1)
(factorial 2)
(factorial 3)
(factorial 4)
(factorial 5)
(factorial 6)
(factorial 7)
(factorial 8)
(factorial 9)
(factorial 10)

(define (square x) (* x x))
(define (double x) (* 2 x))

(define (compute-pi n)
  (define (f n)
    (/ (* (double n) (+ (double n) 2))
       (square (+ (double n) 1))))
  (* 4.0 (prod 1 n f inc)))

(define (compute-pi-iter n)
  (define (f n)
    (/ (* (double n) (+ (double n) 2))
       (square (+ (double n) 1))))
  (* 4.0 (prod-iter 1 n f inc)))

(compute-pi 1000)
(compute-pi-iter 10000)
