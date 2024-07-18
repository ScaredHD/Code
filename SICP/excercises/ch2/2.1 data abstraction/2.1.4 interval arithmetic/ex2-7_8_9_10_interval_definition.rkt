#lang sicp

(define (add-interval x y)
  (make-interval
   (+ (lower-bound x) (lower-bound y))
   (+ (upper-bound x) (upper-bound y))))


(define (mul-interval x y)
  (let ((p1 (* (lower-bound x) (lower-bound y)))
        (p2 (* (lower-bound x) (upper-bound y)))
        (p3 (* (upper-bound x) (lower-bound y)))
        (p4 (* (upper-bound x) (upper-bound y))))
    (make-interval
     (min p1 p2 p3 p4)
     (max p1 p2 p3 p4))))

(define (div-interval x y)
  (if (> (* (lower-bound y) (upper-bound y)) 0)
      (mul-interval
       x
       (make-interval (/ 1.0 (upper-bound y)) (/ 1.0 (lower-bound y))))
      (error "interval contains 0")))


; -------- 2.7 ---------

(define (make-interval x y)
  (cons x y))

(define (lower-bound interval)
  (car interval))

(define (upper-bound interval)
  (cdr interval))

; -------- 2.8 ---------

(define (sub-interval x y)
  (make-interval
   (- (lower-bound x) (upper-bound y))
   (- (upper-bound x) (lower-bound y))))


; -------- 2.9 ---------

(define (width interval)
  (/ (- (upper-bound interval) (lower-bound interval) 2.0)))


(define x (make-interval 3.0 4.0))
(define y (make-interval -3.0 4.0))

(add-interval x y)
(mul-interval x y)
(sub-interval x y)
(div-interval x y)
