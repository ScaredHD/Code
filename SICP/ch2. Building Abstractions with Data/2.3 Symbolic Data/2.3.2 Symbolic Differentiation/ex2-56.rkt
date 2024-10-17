#lang racket

(require "symbolic_differentiation.rkt")

(define (D e var)
  (cond ((number? e) 0)
        ((variable? e) (if (same-variable? e var) 1 0))
        ((sum? e) (make-sum
                   (D (addend e) var)
                   (D (augend e) var)))
        ((product? e) (make-sum
                       (make-product
                        (multiplier e)
                        (D (multiplicand e) var))
                       (make-product
                        (D (multiplier e) var)
                        (multiplicand e))))
        ((exponentiation? e) (let ([b (base e)][n (exponent e)])
                               (make-product3
                                n
                                (make-exponentiation b (- n 1))
                                (D b var))))))

(define (make-product3 x y z)
  (make-product (make-product x y) z))

(define (make-exponentiation b e)
  (cond ((=number? e 0) 1)
        ((=number? e 1) b)
        (else (list '** b e))))

(define (exponentiation? e) (and (pair? e) (eq? (car e) '**)))

(define (base e) (cadr e))

(define (exponent e) (caddr e))

(D '(+ x 3) 'x)
(D '(* x y) 'x)
(D '(* (* x y) (+ x 3)) 'x)
(D '(** x 3) 'x)

