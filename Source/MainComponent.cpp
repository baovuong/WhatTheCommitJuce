/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "MainComponent.h"


//==============================================================================
MainContentComponent::MainContentComponent()
{
	commitMessage = new CommitMessageComponent();
	addAndMakeVisible(commitMessage);
	
	generateCommitButton = new TextButton();
	generateCommitButton->setButtonText("Generate Commit Message");
	generateCommitButton->addListener(this);
	addAndMakeVisible(generateCommitButton);
	
	setSize (600, 400);
}

MainContentComponent::~MainContentComponent()
{
}

void MainContentComponent::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));

    g.setFont (Font (16.0f));
    g.setColour (Colours::white);
    g.drawText ("Hello World!", getLocalBounds(), Justification::centred, true);
}

void MainContentComponent::resized()
{
    // This is called when the MainContentComponent is resized.
    // If you add any child components, this is where you should
    // update their positions.
	commitMessage->setBounds(5, 5, getWidth() - 10, getHeight()*0.75 - 5);
	
	generateCommitButton->setBounds(
	    5, 
	    commitMessage->getBounds().getY() + commitMessage->getBounds().getHeight() + 5, 
	    getWidth() - 10, 
	    getHeight()*0.25 - 10);
}

void MainContentComponent::buttonClicked(Button* button)
{
    if (button == generateCommitButton)
    {
        commitMessage->generateMessage();
    }
}