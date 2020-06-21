from sqlalchemy.engine import create_engine
from sqlalchemy.ext.declarative.api import declarative_base
from sqlalchemy.orm.session import sessionmaker

engine=create_engine('oracle://vineeth:vineeth@localhost:1521/XE', echo=True)
Session = sessionmaker(bind=engine)
Base=declarative_base()