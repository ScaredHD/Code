#lang racket

(require "sets_as_binary_trees.rkt")

(define (tree->list-1 tree)
  (if (null? tree)
      '()
      (append (tree->list-1 (left tree))
              (cons (val tree)
                    (tree->list-1 (right tree))))))

(define (tree->list-2 tree)
  (define (copy-to-list tree dst)
    (if (null? tree)
        dst
        (copy-to-list (left tree)
                      (cons (val tree)
                            (copy-to-list (right tree)
                                          dst)))))
  (copy-to-list tree '()))

(define t '(3
            (1 () ())
            (7
             (5 () ())
             (9 () (11 () ())))))

(tree->list-1 t)
(tree->list-2 t)

; a) both functions achieve in-order traversal, therefore give same results

; b) tree->list-1 is O(n log(n)), tree->list-2 is O(n)
;  T1(n) = 2 * T1(n / 2) + O(n/2)   (extra O(n/2) is for appending the lists)
;  T2(n) = 2 * T2(n / 2) + O(1)