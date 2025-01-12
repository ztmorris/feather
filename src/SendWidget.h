// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: 2020-2023 The Monero Project

#ifndef FEATHER_SENDWIDGET_H
#define FEATHER_SENDWIDGET_H

#include <QWidget>

#include "appcontext.h"
#include "widgets/CCSWidget.h"

namespace Ui {
    class SendWidget;
}

class SendWidget : public QWidget
{
Q_OBJECT

public:
    explicit SendWidget(QSharedPointer<AppContext> ctx, QWidget *parent = nullptr);
    void fill(const QString &address, const QString &description, double amount = 0);
    void fill(double amount);
    void clearFields();
    void payToMany();
    ~SendWidget() override;

public slots:
    void skinChanged();
    void scanClicked();
    void sendClicked();
    void clearClicked();
    void aliasClicked();
    void btnMaxClicked();
    void amountEdited(const QString &text);
    void addressEdited();
    void currencyComboChanged(int index);
    void fillAddress(const QString &address);
    void updateConversionLabel();
    void onOpenAliasResolveError(const QString &err);
    void onOpenAliasResolved(const QString &openAlias, const QString &address, bool dnssecValid);
    void onPreferredFiatCurrencyChanged();
    void disableSendButton();

    void onInitiateTransaction();
    void onEndTransaction();

private slots:
    void onDataPasted(const QString &data);

private:
    void setupComboBox();
    double amountDouble();

    quint64 amount();
    double conversionAmount();

    QScopedPointer<Ui::SendWidget> ui;
    QSharedPointer<AppContext> m_ctx;
    bool m_sendDisabled = false;
};

#endif // FEATHER_SENDWIDGET_H
