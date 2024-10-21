import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler
from sklearn.neural_network import MLPClassifier
from sklearn.metrics import confusion_matrix, classification_report
import matplotlib.pyplot as plt
import seaborn as sns

# Descargar la base de datos Wine Quality de UCI
url = "https://archive.ics.uci.edu/ml/machine-learning-databases/wine-quality/winequality-red.csv"

# Importar los datos
data = pd.read_csv(url, sep=';')

# Separar características y etiquetas
X = data.drop('quality', axis=1)
y = data['quality']

# Dividir los datos en conjunto de entrenamiento y prueba (80% y 20%)
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)

# Estandarizar los datos
scaler = StandardScaler()
X_train_scaled = scaler.fit_transform(X_train)
X_test_scaled = scaler.transform(X_test)

# Crear y entrenar la red neuronal (Perceptrón Multicapa)
mlp = MLPClassifier(hidden_layer_sizes=(10, 10, 10), max_iter=1000, random_state=42)
mlp.fit(X_train_scaled, y_train)

# Graficar la curva de entrenamiento (pérdida)
plt.plot(mlp.loss_curve_)
plt.title('Curva de entrenamiento (pérdida)')
plt.xlabel('Iteraciones')
plt.ylabel('Pérdida')
plt.show()

# Predecir con los datos de prueba
y_pred = mlp.predict(X_test_scaled)

# Calcular la matriz de confusión
conf_matrix = confusion_matrix(y_test, y_pred)

# Graficar la matriz de confusión
plt.figure(figsize=(8, 6))
sns.heatmap(conf_matrix, annot=True, fmt='d', cmap='Blues', xticklabels=mlp.classes_, yticklabels=mlp.classes_)
plt.title('Matriz de Confusión')
plt.ylabel('Valores Reales')
plt.xlabel('Valores Predichos')
plt.show()

# Mostrar el reporte de clasificación
print("Reporte de clasificación:")
print(classification_report(y_test, y_pred))
