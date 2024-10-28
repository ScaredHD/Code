#lang racket

(provide (all-defined-out))

(define (attach-tag tag content)
  (cons tag content))

(define (type-tag data)
  (if (pair? data) (car data) (error "Bad tagged data: TYPE-TAG" data)))

(define (contents data)
  (if (pair? data) (cdr data) (error "Bad tagged data: CONTENT" data)))