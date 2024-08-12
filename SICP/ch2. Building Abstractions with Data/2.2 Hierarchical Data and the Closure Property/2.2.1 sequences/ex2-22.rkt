#lang sicp

(define (square x) (* x x))

(define (square-list-wrong items)
  (define (iter things answer)
    (if (null? things)
        answer
        (iter (cdr things)
              (cons (square (car things))
                    answer))))
  (iter items nil))

; answer appears as the second argument in cons,
; next squared element (first argument) is constructed to the left of answer,
; therefore order reverses.

(define (square-list-wrong2 items)
  (define(iter things answer)
    (if(null? things)
       answer
       (iter (cdr things)
             (cons answer
                   (square(car things))))))
  (iter items nil))

; second argument of cons should be a list, but here it is a number
; first argument is a list, the inner most one is nil, therefore procedure works like this
; ()
; ((), 1)
; (((), 1), 4)
; ...

(square-list-wrong (list 1 2 3 4 5))
(square-list-wrong2 (list 1 2 3 4 5))