#lang sicp

(define (cons x y)
  (lambda (m) (m x y)))

(define (car z)
  (z (lambda (p q) p)))

(define (cdr z)
  (z (lambda (p q) q)))

(car (cons 3.1415 42))
; (car (lambda (m) (m 3.1415 42)))
; ((lambda (m) (m 3.1415 42)) (lambda (p q) p))
; ((lambda (p q) p) 3.1415 42)
; 3.1415

(cdr (cons 3.1415 42))

