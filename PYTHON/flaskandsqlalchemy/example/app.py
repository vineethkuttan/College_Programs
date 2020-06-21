from flask.app import Flask
from flask_sqlalchemy import SQLAlchemy
app = Flask(__name__)
app.config['SQLALCHEMY_DATABASE_URI']='oracle://vineethkuttan:hero@localhost:1521/XE'
db=SQLAlchemy(app)
class User(db.Model):
    __tablename__="tbl_user"
    id=db.Column(db.Integer,primary_key=True)
    name=db.Column(db.String(20))
    address=db.Column(db.String(20))
@app.route('/home/<int:id>/<name>/<address>')
def index(id,name,address):
    user=User(id=id,name=name,address=address)
    db.session.add(user)
    db.session.commit()
    return f"<h1>Added new USER {id} {name} {address}</h1>"
if __name__=="__main__":
    db.create_all()
    app.run(port=8090,debug=True)
