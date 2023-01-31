#ifndef TRANSPERANT_H
#define TRANSPERANT_H

#include <QWidget>

class Transperant : public QWidget
{
		Q_OBJECT
	public:
		Transperant(QWidget *parent = nullptr);
	protected:
		virtual void paintEvent(QPaintEvent*event) override;
	private:
		bool isMouseOver;


		// QWidget interface
	protected:
		virtual void enterEvent(QEnterEvent*event) override;
		virtual void leaveEvent(QEvent*event) override;
};

#endif // TRANSPERANT_H
