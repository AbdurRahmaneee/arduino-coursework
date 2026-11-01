grades=[]
num_grades = int(input("How many grades do you have? "))
for i in range(0,num_grades,1):
    grade=float(input("Enter your " + str(i+1) + " Grade: "))
    grades.append(grade)
sorted_grades=[]
print(" ")
for j in range(0, num_grades-2
for i in range(0, num_grades-1, 1):
        if grades[i]<grades[i+1]:
            tmp = grades[i+1]
            grades[i+1]=grades[i]
            grades[i]=tmp

print("YOur grades are: ")
for i in range(0, num_grades, 1):
    print(grades[i])
    
bucket = 0
for i in range(0, num_grades, 1):
    bucket=bucket+grades[i]
gradeAvg = bucket/num_grades
print("your  average is ", gradeAvg)

if gradeAvg < 60:
    print("you have failed the class")
if gradeAvg < 70 and gradeAvg >=60:
    print("you have made a D in class")
if gradeAvg < 80 and gradeAvg>=70:
    print("you have made a C in class")
if gradeAvg < 90 and gradeAvg>=80:
    print("you have made a B in class")
if gradeAvg >= 90:
    print("you have made a A in class")
    