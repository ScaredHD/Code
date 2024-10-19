#lang racket

(provide (all-defined-out))

; tree node representation
; (root node value, left subtree root, right subtree root)
(define (val node) (car node))
(define (left node) (cadr node))
(define (right node) (caddr node))
(define (tree root-val l r) (list root-val l r))

(define (in? x s)
  (cond ((null? s) false)
        ((= x (val s)) true)
        ((< x (val s)) (in? x (left s)))
        ((> x (val s)) (in? x (right s)))))

(define (adjoint x s)
  (cond ((null? s) (tree x '() '()))
        ((= x (val s)) s)
        ((< x (val s)) (tree (val s)
                             (adjoint x (left s))
                             (right s)))
        ((> x (val s)) (tree (val s)
                             (left x)
                             (adjoint x (right s))))))

