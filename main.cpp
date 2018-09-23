#include <QApplication>
#include <QWidget>
#include <QWebEngineView>
#include <QHBoxLayout>
#include <QThread>

#include "r_core.h"

RCore *core;

void LoadR2();

class R2Thread : public QThread
{
	Q_OBJECT

	private:
		void run() override
		{
			LoadR2();
		}
};

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

	QWidget window;
	window.resize(640, 480);

	QLayout *layout = new QHBoxLayout(&window);

	auto web_engine_view = new QWebEngineView(&window);
	layout->addWidget(web_engine_view);

	R2Thread th;
	th.start();

	web_engine_view->load(QUrl("https://rada.re"));

	window.show();
	QApplication::setQuitOnLastWindowClosed(true);
	return QApplication::exec();
}

void LoadR2()
{
	core = r_core_new();
	r_core_file_open(core, "/home/florian/dev/radare2/radare2-regressions/bins/elf/analysis/mips-hello", R_PERM_R, 0);
	r_core_bin_load(core, "/home/florian/dev/radare2/radare2-regressions/bins/elf/analysis/mips-hello", 0);
	r_core_cmd(core, "aaa", 0);
	r_cons_flush();
}

#include "main.moc"