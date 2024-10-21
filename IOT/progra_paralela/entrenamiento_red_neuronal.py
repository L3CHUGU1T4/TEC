# Importar las bibliotecas necesarias
import pandas as pd  # Para manejar los datos en formato DataFrame
from sklearn.model_selection import train_test_split  # Para dividir los datos en entrenamiento y prueba
from sklearn.preprocessing import StandardScaler  # Para escalar (normalizar) las características
from sklearn.neural_network import MLPClassifier  # Para crear y entrenar un modelo de red neuronal (Perceptrón Multicapa)
from sklearn.metrics import confusion_matrix, classification_report  # Para evaluar el rendimiento del modelo
import matplotlib.pyplot as plt  # Para graficar la curva de entrenamiento y matriz de confusión
import seaborn as sns  # Para crear gráficos más atractivos, como la matriz de confusión
from sklearn.utils import resample  # Para re-muestrear las clases y equilibrar el conjunto de datos

# Definir la URL de los datos de Wine Quality desde el repositorio UCI
url = "https://archive.ics.uci.edu/ml/machine-learning-databases/wine-quality/winequality-red.csv"

# Cargar los datos desde la URL en un DataFrame usando pandas
data = pd.read_csv(url, sep=';')  # Los datos están separados por ';' en el archivo CSV

# Separar las características (X) de la etiqueta de calidad (y)
X = data.drop('quality', axis=1)  # X contiene todas las columnas excepto la columna 'quality'
y = data['quality']  # y contiene únicamente la columna 'quality', que es la variable objetivo

# Combinar las características y etiquetas en un solo DataFrame para re-muestrear después
data_combined = pd.concat([X, y], axis=1)  # Concatenar las características y etiquetas en un solo DataFrame

# Identificar las clases minoritarias de calidad de vino que serán sobremuestreadas
# Clases minoritarias: 3, 4, y 8 (estas clases tienen pocas muestras en comparación con otras)
class_minority_3 = data_combined[data_combined['quality'] == 3]  # Filtrar las muestras con calidad 3
class_minority_4 = data_combined[data_combined['quality'] == 4]  # Filtrar las muestras con calidad 4
class_minority_8 = data_combined[data_combined['quality'] == 8]  # Filtrar las muestras con calidad 8

# Identificar la clase mayoritaria (en este caso, la clase con calidad 5) y obtener el número de muestras
data_combined_majority = data_combined[data_combined['quality'] == 5]  # Filtrar las muestras con calidad 5
n_majority = data_combined_majority.shape[0]  # Obtener el número de muestras de la clase mayoritaria

# Sobremuestrear las clases minoritarias para que tengan el mismo número de muestras que la clase mayoritaria
class_minority_3_upsampled = resample(class_minority_3, replace=True, n_samples=n_majority, random_state=42)
class_minority_4_upsampled = resample(class_minority_4, replace=True, n_samples=n_majority, random_state=42)
class_minority_8_upsampled = resample(class_minority_8, replace=True, n_samples=n_majority, random_state=42)

# Combinar el conjunto de datos sobremuestreados de clases minoritarias con la clase mayoritaria
data_upsampled = pd.concat([data_combined_majority, class_minority_3_upsampled, class_minority_4_upsampled, class_minority_8_upsampled])

# Separar nuevamente las características (X) y las etiquetas (y) después del sobremuestreo
X_upsampled = data_upsampled.drop('quality', axis=1)  # Características después del re-muestreo
y_upsampled = data_upsampled['quality']  # Etiquetas (calidad) después del re-muestreo

# Dividir el conjunto de datos re-muestreados en entrenamiento (80%) y prueba (20%)
X_train, X_test, y_train, y_test = train_test_split(X_upsampled, y_upsampled, test_size=0.2, random_state=42)

# Estandarizar los datos: ajustar las características para que tengan media 0 y desviación estándar 1
scaler = StandardScaler()  # Crear un objeto para escalar los datos
X_train_scaled = scaler.fit_transform(X_train)  # Ajustar y transformar el conjunto de entrenamiento
X_test_scaled = scaler.transform(X_test)  # Transformar el conjunto de prueba usando la misma escala

# Crear un modelo de Perceptrón Multicapa (MLP) con tres capas ocultas de 10 neuronas cada una
mlp = MLPClassifier(hidden_layer_sizes=(10, 10, 10), max_iter=2000, random_state=42)

# Entrenar el modelo de red neuronal con los datos de entrenamiento escalados
mlp.fit(X_train_scaled, y_train)

# Graficar la curva de pérdida (función de pérdida) para observar cómo evoluciona durante el entrenamiento
plt.plot(mlp.loss_curve_)  # La curva de pérdida muestra cómo el modelo minimiza el error durante el entrenamiento
plt.title('Curva de entrenamiento (pérdida)')  # Título del gráfico
plt.xlabel('Iteraciones')  # Etiqueta para el eje x (número de iteraciones)
plt.ylabel('Pérdida')  # Etiqueta para el eje y (valor de la pérdida)
plt.show()  # Mostrar el gráfico

# Hacer predicciones en el conjunto de datos de prueba escalado
y_pred = mlp.predict(X_test_scaled)

# Calcular la matriz de confusión para evaluar las predicciones del modelo
conf_matrix = confusion_matrix(y_test, y_pred)

# Graficar la matriz de confusión para visualizar los resultados de las predicciones
plt.figure(figsize=(8, 6))  # Configurar el tamaño de la figura
sns.heatmap(conf_matrix, annot=True, fmt='d', cmap='Blues', xticklabels=mlp.classes_, yticklabels=mlp.classes_)
plt.title('Matriz de Confusión')  # Título del gráfico
plt.ylabel('Valores Reales')  # Etiqueta para el eje y (valores verdaderos)
plt.xlabel('Valores Predichos')  # Etiqueta para el eje x (valores predichos)
plt.show()  # Mostrar el gráfico

# Mostrar el reporte de clasificación con métricas como precisión, recall, y F1-score
# Se usa zero_division=1 para evitar errores en caso de divisiones por cero
print("Reporte de clasificación:")
print(classification_report(y_test, y_pred, zero_division=1))
