#lang sicp

(cons 1 (cons 2 (cons 3 (cons 4 nil))))

(define one-through-four (list 1 2 3 4))

(car one-through-four)
(cdr one-through-four)
(car (cdr one-through-four))
(cadr one-through-four)
(caddr one-through-four)
(cadddr one-through-four)



