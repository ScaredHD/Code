#lang racket

; (#%require "../../ch2_common.rkt")
(#%require (only sicp nil))

(define (accumulate op init seq)
  (if (null? seq)
      init
      (op (car seq)
          (accumulate op init (cdr seq)))))

(define (accumulate-n op init seqs)
  (if (null? (car seqs))
      nil
      (cons (accumulate op init (map car seqs))
            (accumulate-n op init (map cdr seqs)))))

(define (dot-product v w)
  (accumulate + 0 (map * v w)))


(define (matrix-*-vector m v)
  (map (lambda (x) (dot-product x v)) m))

(define (transpose m)
  (accumulate-n cons nil m))

(define (matrix-*-matrix m n)
  (let ((cols (transpose n)))
    (map (lambda (row)
           (map (lambda (col)
                  (dot-product row col))
                cols))
         m)))

(dot-product (list 1 2 3) (list 4 5 6))

(define m (list (list 1 2 3)
                (list 4 5 6)
                (list 7 8 9)))

(matrix-*-vector m (list 1 2 3))

(transpose m)

(matrix-*-matrix m m)