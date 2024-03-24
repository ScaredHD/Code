#lang sicp

(define (a-plus-abs-b a b)
  ((if (> b 0) + -) a b))

; if b > 0, then the body is (+ a b)
; otherwise the body is (- a b)
; that is a + abs(b)

(a-plus-abs-b 1 3)
(a-plus-abs-b 2 -4)
(a-plus-abs-b 0 3)
(a-plus-abs-b 0 -3)