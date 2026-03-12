import pandas as pd
import numpy as np

from tensorflow import keras
from keras import layers
from keras.models import Sequential
from keras.layers import Dense
from keras.optimizers import Adam
import time

from sklearn.model_selection import train_test_split

df = pd.read_csv("dataset.csv")

df["digest_bytes"] = df["digest"].apply(bytes.fromhex)

def mask_digest(b):
    arr = np.zeros(32, dtype=np.uint8)
    arr[:len(b)] = list(b)
    return arr

X = np.stack(df["digest_bytes"].apply(mask_digest).values).astype("float32") / 255.0
label_names, y = np.unique(df["hash_name"], return_inverse=True)

X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42, stratify=y)

model = Sequential([Dense(64, activation="relu", input_shape=(32,)), Dense(32, activation="relu"), Dense(len(label_names), activation="softmax")])
model.compile(optimizer=Adam(learning_rate=0.001), loss="sparse_categorical_crossentropy", metrics=["accuracy"])

start = time.time()

history = model.fit(X_train, y_train, validation_split=0.2, epochs=40, batch_size=32, verbose=1)
test_loss, test_acc = model.evaluate(X_test, y_test, verbose=0)

end = time.time()

print("Test accuracy:", test_acc)
print("Training time:", end - start)

pred = model.predict(X_test[:10], verbose=0)
pred_labels = np.argmax(pred, axis=1)

for i in range(10):
    print("initial =", label_names[y_test[i]], "vs. pred =", label_names[pred_labels[i]])

df2 = df[df["hash_name"].isin(["sha256", "sha3_256"])].copy()
df2["digest_bytes"] = df2["digest"].apply(bytes.fromhex)

X2 = np.stack(df2["digest_bytes"].apply(lambda b: np.array(list(b), dtype=np.uint8)).values).astype("float32") / 255.0
label_names2, y2 = np.unique(df2["hash_name"], return_inverse=True)

X2_train, X2_test, y2_train, y2_test = train_test_split(X2, y2, test_size=0.2, random_state=42, stratify=y2)

model2 = Sequential([Dense(64, activation="relu", input_shape=(32,)), Dense(32, activation="relu"), Dense(len(label_names2), activation="softmax")])
model2.compile(optimizer=Adam(learning_rate=0.001), loss="sparse_categorical_crossentropy", metrics=["accuracy"])

history2 = model2.fit(X2_train, y2_train, validation_split=0.2, epochs=40, batch_size=32, verbose=1)

test_loss2, test_acc2 = model2.evaluate(X2_test, y2_test, verbose=0)
print("Test accuracy sha256 vs sha3_256:", test_acc2)