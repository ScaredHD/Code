#lang sicp

(define (p) (p))
(define (test x y)
  (if (= x 0) 0 y))


(test 0 (p))

; Applicative order: infinite loop
; Evaluate all arguments and then apply

; Normal order: 0
; Expand fully and then reduce 