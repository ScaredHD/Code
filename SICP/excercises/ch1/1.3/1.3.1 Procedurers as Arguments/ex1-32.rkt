#lang sicp

(define (accumulate combiner null-value term a next b)
  (if (> a b)
    null-value
    (combiner (term a) (accumulate combiner null-value term (next a) next b))))
  
(define (sum term a next b)
  (define (sum-combine x y) (+ x y))
  (accumulate sum-combine 0 term a next b))

(define (prod term a next b)
  (define (prod-combine x y) (* x y))
  (accumulate prod-combine 1 term a next b))

(define (cube x) (* x x x))

(sum cube 1 inc 10)

(prod identity 1 inc 5)

(define (accumulate-iter combiner null-value term a next b)
  (define (iter cur res)
    (if (> cur b)
      res
      (iter (next cur) (combiner res (term cur)))))
  (iter a null-value))

(define (sum-iter term a next b)
  (define (sum-combine x y) (+ x y))
  (accumulate-iter sum-combine 0 term a next b))

(define (prod-iter term a next b)
  (define (prod-combine x y) (* x y))
  (accumulate-iter prod-combine 1 term a next b))

(sum-iter cube 1 inc 10)

(prod-iter identity 1 inc 5)