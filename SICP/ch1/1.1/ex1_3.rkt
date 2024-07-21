#lang sicp

(define (sum-of-square a b)
  (+ (* a a) (* b b)))

(define (f a b c)
  (cond ((and (<= a b) (<= a c)) (sum-of-square b c))
        ((and (<= b a) (<= b c)) (sum-of-square a c))
        ((and (<= c a) (<= c b)) (sum-of-square a b))
  ))

(f 1 2 3)
(f 2 1 3)
(f 3 2 1)
(f 2 2 2)
(f 2 2 3)
(f 2 3 3)
(f 3 1 3)