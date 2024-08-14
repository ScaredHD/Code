#lang sicp

(#%require "../../ch2_common.rkt")

(define (poly-eval x coeff)
  (accumulate (lambda (y z)
                (+ (* z x) y))
              0
              coeff))

(poly-eval 2 (list 1 3 0 5 0 1))

(define p (lambda (x) (+ (* x x x x x)
                         (* 5 (* x x x))
                         (* 3 x)
                         1 )))

(p 2)