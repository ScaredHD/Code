#lang racket

(define (Equal? a b)
  (cond ((and (pair? a) (pair? b)) (and (Equal? (car a) (car b)) (Equal? (cdr a) (cdr b))))
        (else (eq? a b))))

(Equal? 42 42)

(Equal? 114 514)

(Equal? 'something 'something)

(Equal? (list 'a 'b) (list 'a 'b))

(Equal? (list 1 2 3) (list (list 1 2) 3))

(Equal? '(a b (c d)) (list 'a 'b (list 'c 'd)))