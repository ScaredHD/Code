#lang sicp

(define a (list 1 2 (list 5 7) 9))

(define b (list (list 7)))

(define c (list 1 (list 2 (list 3 (list 4 (list 5 (list 6 7)))))))

a
b
c

(car (cdaddr a))
(caar b)
(cadr (cadr (cadr (cadr (cadr (cadr c))))))