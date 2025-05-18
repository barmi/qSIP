#include "SettingAudioDeviceForm.h"
#include "ui_SettingAudioDeviceForm.h"

#include <QMediaDevices>
#include <QAudioDevice>

SettingAudioDeviceForm::SettingAudioDeviceForm(QWidget *parent)
	: AbstractSettingForm(parent)
	, ui(new Ui::SettingAudioDeviceForm)
{
	ui->setupUi(this);

	QString def = "default";
	ui->comboBox_input->addItem(def);
	ui->comboBox_output->addItem(def);

    const QList<QAudioDevice> inputdevs = QMediaDevices::audioInputs();
    for (auto const &device : inputdevs) {
        if (device.description() == def) continue;
        ui->comboBox_input->addItem(device.description());
    }

    const QList<QAudioDevice> outputdevs = QMediaDevices::audioOutputs();
    for (auto const &device : outputdevs) {
        if (device.description() == def) continue;
        ui->comboBox_output->addItem(device.description());
    }
}

void SettingAudioDeviceForm::exchange(bool save)
{
	ApplicationSettings *as = settings();
	if (save) {
		as->audio_input = ui->comboBox_input->currentText();
		as->audio_output = ui->comboBox_output->currentText();
	} else {
		ui->comboBox_input->setCurrentText(as->audio_input);
		ui->comboBox_output->setCurrentText(as->audio_output);
	}
}
