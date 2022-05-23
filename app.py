from flask import *
app = Flask(__name__)

access_token = "o.swcV5D0plpoiUysGwAJPwmy6R9TzHFSl"

@app.route('/')
def hello_world():
    key = request.args.get("key")
    return f'Hello, World! {key}'

if __name__ == '__main__':
    app.run()