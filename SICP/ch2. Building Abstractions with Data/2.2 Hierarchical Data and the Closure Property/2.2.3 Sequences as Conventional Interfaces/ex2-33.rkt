#lang sicp

(#%require "../../ch2_common.rkt")

(define (sum-odd-squares tree)
  (accumulate + 0 (map square (filter odd? (enumerate-leave tree)))))

(sum-odd-squares (list 1 (list 2 (list 3 4) 5)))