from flask import Flask, render_template, request, redirect
from cs50 import SQL

app = Flask(__name__)

db = SQL("sqlite:///planner.db")


@app.route("/")
def index():

    courses = db.execute("SELECT * FROM courses")

    total_points = 0
    total_credits = 0

    for course in courses:
        total_points += course["grade"] * course["credits"]
        total_credits += course["credits"]

    if total_credits > 0:
        gpa = round(total_points / total_credits, 2)
    else:
        gpa = 0
    
    course_count = len(courses)

    return render_template(
    "index.html",
    courses=courses,
    gpa=gpa,
    course_count=course_count,
    total_credits=total_credits
)


@app.route("/add", methods=["POST"])
def add():

    name = request.form.get("name")
    credits = request.form.get("credits")
    grade = request.form.get("grade")

    db.execute(
        "INSERT INTO courses (name, credits, grade) VALUES (?, ?, ?)",
        name,
        credits,
        grade
    )

    return redirect("/")

@app.route("/delete/<int:course_id>")
def delete(course_id):

    db.execute("DELETE FROM courses WHERE id = ?", course_id)

    return redirect("/")

@app.route("/predict", methods=["GET", "POST"])
def predict():

    result = None
    message = None

    if request.method == "POST":
        current_score = float(request.form.get("current_score"))
        current_weight = float(request.form.get("current_weight")) / 100
        final_weight = float(request.form.get("final_weight")) / 100
        desired_grade = float(request.form.get("desired_grade"))

        needed_final = (desired_grade - (current_score * current_weight)) / final_weight
        result = round(needed_final, 2)

        if result > 100:
            message = "This goal is not possible because you would need more than 100 on the final exam."
        elif result <= 0:
            message = "You have already secured this goal based on your current score."
        else:
            message = f"You need {result} on the final exam."

    return render_template("predict.html", result=result, message=message)

@app.route("/edit/<int:course_id>", methods=["GET", "POST"])
def edit(course_id):

    if request.method == "POST":
        name = request.form.get("name")
        credits = request.form.get("credits")
        grade = request.form.get("grade")

        db.execute(
            "UPDATE courses SET name = ?, credits = ?, grade = ? WHERE id = ?",
            name,
            credits,
            grade,
            course_id
        )

        return redirect("/")

    course = db.execute("SELECT * FROM courses WHERE id = ?", course_id)[0]

    return render_template("edit.html", course=course)

if __name__ == "__main__":
    app.run(debug=True)