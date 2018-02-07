import numpy as np
from sklearn import neighbors, datasets     
 
# Load iris data from 'datasets module'
iris = datasets.load_iris()
#   Get data-records and record-labels in arrays X and y
X=iris.data
y=iris.target<pre>
# Create an instance of KNeighborsClassifier and then fit training data
clf = neighbors.KNeighborsClassifier()
clf.fit(X, y)
# Make class predictions for all observations in X
Z = clf.predict(X)
# Compare predicted class labels with actual class labels
accuracy=clf.score(X,y)
print ("Predicted model accuracy: "+ str(accuracy))
# Add a row of predicted classes to y-array for ease of comparison
A = np.vstack([y, Z])
print(A)
