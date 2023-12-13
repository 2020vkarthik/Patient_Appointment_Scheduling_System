#Flask Application For Backend Server

from flask import Flask, render_template, request
import subprocess
app = Flask(__name__)
@app.route('/', methods=['GET', 'POST'])
def index():
 if request.method == 'POST':
 print("Form Data:", request.form)
 algorithm = request.form['algorithm']
 n = request.form['n']
 time_quantum = request.form['time_quantum']
 c_program = "./scheduler"
 args = [algorithm, n, time_quantum]
 for i in range(1, int(n) + 1):
 arrival_time = request.form[f"arrival_time_{i}"]
 burst_time = request.form[f"burst_time_{i}"]
 priority = request.form[f"priority_{i}"]
 args.extend([arrival_time, burst_time, priority])
 try:
 result = subprocess.check_output([c_program] + args,
stderr=subprocess.STDOUT, text=True)
 print(f"{result}")
 except subprocess.CalledProcessError as e:
 result = f"Error: {e.output}"
 return render_template('result.html', algorithm=algorithm, n=n,
time_quantum=time_quantum, result=result)
 return render_template('index.html')
if __name__ == '__main__':
 app.run(debug=True)
