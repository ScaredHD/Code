#lang racket

; (require "sets_as_ordered_lists.rkt")

(define (union s1 s2)
  (cond ((null? s1) s2)
        ((null? s2) s1)
        (else (let ([x1 (car s1)]
                    [x2 (car s2)])
                (cond
                  ((< x1 x2) (cons x1 (union (cdr s1) s2)))
                  ((> x1 x2) (cons x2 (union s1 (cdr s2))))
                  ((= x1 x2) (cons x1 (union (cdr s1) (cdr s2)))))))))


(union '(1 3 5 7) '(1 2 3 4))
(union '() '(1 3 5))
(union '(2 4 6) '())
(union '() '())