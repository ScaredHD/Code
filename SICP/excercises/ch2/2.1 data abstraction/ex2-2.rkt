#lang sicp

(define (make-point x y)
  (cons x y))

(define (x-point p)
  (car p))

(define (y-point p)
  (cdr p))

(define (print-point p)
  (newline)
  (display "(")
  (display (x-point p))
  (display ",")
  (display (y-point p))
  (display ")"))

(define (make-segment start end)
  (cons start end))

(define (start-segment segment)
  (car segment))

(define (end-segment segment)
  (cdr segment))

(define (midpoint-segment segment)
  (let ((start (start-segment segment))
        (end (end-segment segment)))
    (make-point
     (/ (+ (x-point start) (x-point end)) 2)
     (/ (+ (y-point start) (y-point end)) 2))))


(define p1 (make-point 1 2))
(define p2 (make-point 3 4))
(define p3 (make-point -1 10))

(define l1 (make-segment p1 p2))
(define l2 (make-segment p2 p3))

(print-point (midpoint-segment l1))
(print-point (midpoint-segment l2))