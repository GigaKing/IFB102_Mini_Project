from flask import *
import requests
app = Flask(__name__)


@app.route('/')
def hello_world():
    key = request.args.get("key")

    token = '5542231187:AAHe62JW_o-070ekbBdEOEnFAIDEXInImec'
    userID = '-1001672321658'
    message = 'Please note your house is on fire'

    # Create url
    url = f'https://api.telegram.org/bot{token}/sendMessage'

    # Create json link with message
    data = {'chat_id': userID, 'text': message}

    # POST the message
    requests.post(url, data)

    return f'Hello, World! {key}'

if __name__ == '__main__':
    app.run(host='0.0.0.0', port=5000)
