**Common Lisp**. 🚀

---

# 📜 **Lisp Cheat Sheet**

## 🔹 **Sintaxis Básica**

```lisp
(+ 2 3)        ; Suma → 5
(- 7 2)        ; Resta → 5
(* 3 4)        ; Multiplicación → 12
(/ 10 2)       ; División → 5
(mod 10 3)     ; Módulo → 1
```

### 🏷 **Definir Variables**

```lisp
(setq x 10)    ; Asigna 10 a x
(setq y (+ x 5)) ; Asigna 15 a y
```

### 📦 **Definir Constantes**

```lisp
(defparameter *pi* 3.1416)  ; Definir una variable global
(defconstant *e* 2.718)     ; Definir una constante
```

---

## 🔹 **Estructuras de Control**

### ✅ **Condicional If**

```lisp
(if (> x 5)
    (format t "x es mayor que 5")
    (format t "x es menor o igual a 5"))
```

### 🔄 **Condición `cond` (anidada)**

```lisp
(cond
  ((> x 10) (format t "Mayor que 10"))
  ((= x 10) (format t "Es 10"))
  (t (format t "Menor que 10")))
```

### 🔄 **Bucles**

#### 🔁 **Loop (contado)**

```lisp
(loop for i from 1 to 5 do (format t "~a " i))
; Output: 1 2 3 4 5
```

#### 🔁 **Loop (hasta cumplir una condición)**

```lisp
(setq i 0)
(loop while (< i 5) do
  (format t "i: ~a " i)
  (setq i (+ i 1)))
```

#### 🔁 **Recursión**

```lisp
(defun factorial (n)
  (if (= n 0)
      1
      (* n (factorial (- n 1)))))
```

---

## 🔹 **Funciones**

### ✨ **Definir Funciones**

```lisp
(defun cuadrado (x)
  (* x x))
```

Llamar función:

```lisp
(cuadrado 4)  ; → 16
```

### ✨ **Funciones Lambda**

```lisp
(lambda (x) (* x x))
((lambda (x) (* x x)) 4) ; → 16
```

---

## 🔹 **Listas (estructura clave en Lisp)**

```lisp
(setq lista '(1 2 3 4 5))   ; Definir lista
(car lista)   ; Primer elemento → 1
(cdr lista)   ; Resto de la lista → (2 3 4 5)
(cons 0 lista) ; Agregar al inicio → (0 1 2 3 4 5)
```

Iterar sobre una lista:

```lisp
(loop for x in lista do (format t "~a " x))
```

---

## 🔹 **Funciones de Alto Orden**

### 🔁 **Map (Aplicar una función a cada elemento)**

```lisp
(mapcar #'(lambda (x) (* x 2)) '(1 2 3 4 5))
; → (2 4 6 8 10)
```

### 🔁 **Filter (Eliminar elementos según condición)**

```lisp
(remove-if #'(lambda (x) (> x 3)) '(1 2 3 4 5))
; → (1 2 3)
```

### 🔁 **Reduce (Acumulador)**

```lisp
(reduce #'+ '(1 2 3 4 5))
; → 15
```

---

## 🔹 **Estructuras de Datos**

### 📌 **Vectores**

```lisp
(setq v (vector 1 2 3 4 5))
(aref v 2)  ; Accede al índice 2 → 3
```

### 📌 **Hash Tables (Diccionarios)**

```lisp
(setq tabla (make-hash-table))
(setf (gethash 'clave tabla) "valor")
(gethash 'clave tabla)  ; → "valor"
```

---

## 🔹 **Entrada y Salida**

### 🖥 **Imprimir en Consola**

```lisp
(format t "Hola, Lisp!~%") ; → Hola, Lisp!
```

### ⌨️ **Leer entrada del usuario**

```lisp
(format t "Ingrese un número: ")
(setq numero (read))
(format t "Ingresaste: ~a" numero)
```

---

## 🚀 **Ejemplo Completo**

```lisp
(defun fibonacci (n)
  (if (<= n 1)
      n
      (+ (fibonacci (- n 1)) (fibonacci (- n 2)))))

(format t "Fibonacci de 6: ~a~%" (fibonacci 6))
```

📌 **Salida:** `Fibonacci de 6: 8`

---

Con esto tienes lo básico para empezar a programar en **Common Lisp**. 🚀 ¡Diviértete explorando! 😃
