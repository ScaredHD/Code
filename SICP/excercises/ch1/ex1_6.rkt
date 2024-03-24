#lang sicp

(define (new-if predicate then-clause else-clause)
  (cond (predicate then-clause)
        (else else-clause)))

(new-if (= 2 3) 0 5)
(new-if (= 1 1) 0 5)

(define (sqrt-iter guess x)
  (new-if (good-enough? guess x)
          guess
          (sqrt-iter (improve guess x) x)))

(define (improve guess x)
  (average guess (/ x guess)))

(define (average x y) (/ (+ x y) 2))

(define (good-enough? guess x) (< (abs (- (square guess) x)) 0.001))

(define (square x) (* x x))

(define (sqrt x) (sqrt-iter 1.0 x))

;(sqrt 9)
; Calling sqrt funcion will result in infinite loop
; Since the interpreter evaluates in applicative order
; That means to evaluate the value of every function parameter 
;   before actually apply the function
; Therefore (else else-clause) line will be evaluated, causing infinite loop