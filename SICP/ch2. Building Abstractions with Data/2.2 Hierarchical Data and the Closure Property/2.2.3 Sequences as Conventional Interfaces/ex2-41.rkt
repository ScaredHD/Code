#lang racket

(require math)

(define (pair-sum lo hi target)
  (filter-not null?
              (map (lambda (x) (foldr append null
                                      (map (lambda (y)
                                             (if (= target (+ x y)) (list x y) null))
                                           (inclusive-range (+ x 1) hi))))
                   (inclusive-range lo hi))))


(define (triple-sum n target)
  (foldr append
         null
         (map (lambda (x)
                (map (lambda (y)
                       (append (list x) y))
                     (pair-sum (+ x 1) (+ n 1) (- target x))))
              (inclusive-range 1 n))))

(triple-sum 15 10)
(triple-sum 20 20)