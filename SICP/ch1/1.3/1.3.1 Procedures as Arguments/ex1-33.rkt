#lang sicp

(define (smallest-divisor n) (find-divisor n 2))

(define (find-divisor n test-divisor)
  (cond ((> (square test-divisor) n) n)
        ((divides? test-divisor n) test-divisor)
        (else (find-divisor n (+ test-divisor 1)))))

(define (divides? a b) (= (remainder b a) 0))

(define (square x) (* x x))

(define (prime? n) 
  (if (> n 1) (= n (smallest-divisor n)) #f))


(define (filtered-accumulate combiner null-value term a next b filter)
  (if (> a b)
      null-value
      (combiner (if (filter a)
                    (term a)
                    null-value)
                (filtered-accumulate combiner null-value term (next a) next b filter))))

(define (sum-of-square-prime a b)
  (filtered-accumulate + 0 square a inc b prime?))

(sum-of-square-prime 1 5)  ; 38


(define (gcd a b)
  (if (= b 0) a (gcd b (remainder a b))))

(define (prod-of-filtered n)
  (define (filter i) (= (gcd i n) 1))
  (filtered-accumulate * 1 identity 1 inc (- n 1) filter))

(prod-of-filtered 10)  ; 189