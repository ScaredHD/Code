#lang sicp

(define (pow b n)
  (if (= n 0) 1 (* (pow b (- n 1)) b)))

; (pow 2 0)
; (pow 2 1)
; (pow 2 2)
; (pow 2 3)
; (pow 2 4)
; (pow 2 5)
; (pow 2 6)
; (pow 2 7)
; (pow 2 8)
; (pow 2 9)
; (pow 2 10)

(define (cons a b)
  (* (pow 2 a) (pow 3 b)))

(define (car x)
  (if (> (remainder x 2) 0)
      0
      (+ 1 (car (/ x 2)))))

(define (cdr x)
  (if (> (remainder x 3) 0)
      0
      (+ 1 (cdr (/ x 3)))))

(define p (cons 10 42))
(car p)
(cdr p)