from example import base
from example import person_model as we
base.Base.metadata.create_all(base.engine)
session=base.Session()
a1=we.Person("Nithesh",50,"CIT street","abc@gmail.com")
a2=we.Person("Surya",3,"KCE street","kce@gmail.com")
#session.add_all([a1,a2])
session.commit()
qry=session.query(we.Person).all()
print(qry)