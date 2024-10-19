#lang racket

(require "sets_as_ordered_lists.rkt")

(define (adjoint x s)
  (if (null? s)
      (list x)
      (let ([s0 (car s)])
        (cond ((= x s0) s)
              ((< x s0) (cons x s))
              ((> x s0) (cons s0 (adjoint x (cdr s))))))))

(define s1 '(1 3 5 7))
(define s2 '(1 2 3 4))

(in? 5 s1)
(intersection s1 s2)
(adjoint 4 s1)
s1
s2

(adjoint 4 '())
(intersection '() '(1 2 3))
(intersection '(1 2 3) '())

