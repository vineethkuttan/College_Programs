from flask import *
from flask_sqlalchemy import *
from sqlalchemy.ext.declarative import declarative_base
from sqlalchemy import *
from sqlalchemy.orm import *
from sqlalchemy import exc
app = Flask(__name__)
app.config['SQLALCHEMY_DATABASE_URI'] = 'oracle://vineeth:vineeth@localhost:1521/xe'
app.config['SQLALCHEMY_TRACK_MODIFICATIONS'] = True
db = SQLAlchemy(app)
class Author(db.Model):
    __tablename__ = 'authors'
    a_id=db.Column(db.Integer,db.Sequence('author_id_seq'),primary_key=True)
    fi_na=db.Column(db.String(80))
    la_na = db.Column(db.String(120))
    book=db.relationship("Book",uselist=False,back_populates="author")
    def __init__(self,a_id,fi_na,la_na):
        self.a_id=a_id
        self.fi_na = fi_na
        self.la_na = la_na

class Book(db.Model):
    __tablename__ = 'books'
    b_id=db.Column(db.Integer,db.Sequence('book_id_seq'),primary_key=True)
    title=db.Column(db.String(80))
    author_id = db.Column(db.Integer,ForeignKey('authors.a_id'))
    author=db.relationship("Author",back_populates="book")
    def __init__(self,b_id,title,author):
        self.b_id=b_id
        self.title = title
        self.author = author
@app.route("/")
def index():
    return render_template("login.html")
@app.route("/register", methods=["GET", "POST"])
def register():
    if request.method == "POST":
        a_id=request.form['id']
        fi_na= request.form['fn']
        la_na= request.form['ln']
        a1 = Author(a_id=a_id,fi_na=fi_na,la_na=la_na)
        b1 = Book(238,'Java',a1)
        db.session.add(b1)
        db.session.commit()
        return render_template("wel.html",name=fi_na)
if __name__ == "__main__":
    db.create_all()
    app.run(debug=True,port=9976)