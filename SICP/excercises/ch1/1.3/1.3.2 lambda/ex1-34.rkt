#lang sicp

(define (square x) (* x x))

(define (f g) (g 2))

(f square)  ; 2

(f (lambda (z) (* z (+ z 1))))  ; 6

; (f f)
; will be come (f 2)
; will be come (2 2)
; error because '2' is not a procedure