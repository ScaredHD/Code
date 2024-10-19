#lang racket

(provide (all-defined-out))

(define (lookup k records)
  (cond ((null? records) false)
        ((equal? k (key (first records)) (first records)))
        (else (lookup k (rest records)))))


(define (key rec)
  (car rec))